#include <uapi/linux/ptrace.h>

#include <linux/sched.h>
#include <linux/nsproxy.h>
#include <linux/fs.h>
#include <linux/ns_common.h>
#include <linux/utsname.h>

BPF_HASH(start, u32);
BPF_HISTOGRAM(dist);

// ref https://github.com/iovisor/bcc/issues/691
static inline bool nodename_is_ok(char *str) {
  char compare[] = "wordpress-6bcd5b856b-blfl4";
  char comparand[sizeof(compare)] = "";
  bpf_probe_read(&comparand, sizeof(comparand), str);
  for (int i = 0; i < sizeof(compare); ++i)
    if (compare[i] != comparand[i])
      return false;
  return true;
}

int do_entry(struct pt_regs *ctx)
{
  u32 pid;
  u64 ts, *val;
  struct task_struct *task;
  task = (struct task_struct *)bpf_get_current_task();
  struct uts_namespace *uns = (struct uts_namespace *)task->nsproxy->uts_ns;
  if (!nodename_is_ok((void *)uns->name.nodename))
    return 0;

  pid = bpf_get_current_pid_tgid();
  ts = bpf_ktime_get_ns();
  start.update(&pid, &ts);
  return 0;
}

int do_return(struct pt_regs *ctx)
{
  u32 pid;
  u64 *tsp, delta;

  pid = bpf_get_current_pid_tgid();
  tsp = start.lookup(&pid);

  if (tsp != 0) {
    delta = bpf_ktime_get_ns() - *tsp;
    dist.increment(bpf_log2l(delta / 1000));
    start.delete(&pid);
  }

  return 0;
}
