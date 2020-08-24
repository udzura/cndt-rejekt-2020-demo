from bcc import BPF
from time import sleep

# b = BPF(src_file = "vfssample-ns.c")
b = BPF(src_file = "vfssample.c")
b.attach_kprobe(event="vfs_read", fn_name="do_entry")
b.attach_kretprobe(event="vfs_read", fn_name="do_return")

print("Tracing... Hit Ctrl-C to end.")

while (1):
    try:
        sleep(1)
    except KeyboardInterrupt:
        break

print()
b["dist"].print_log2_hist("usecs")
exit()
