# -*- mode: ruby -*-
# vi: set ft=ruby :
Vagrant.configure("2") do |config|
  config.vm.box = "generic/ubuntu2004"
  # config.vm.network "forwarded_port", guest: 80, host: 8080
  # config.vm.network "private_network", ip: "192.168.33.10"
  config.vm.synced_folder ".", "/vagrant"
  config.vm.provider "virtualbox" do |vb|
    vb.gui = true
    vb.cpus = 8
    vb.memory = (1024 * 8).to_s
  end
  # config.vm.provision "shell", inline: <<-SHELL
  #   apt-get update
  #   apt-get install -y apache2
  # SHELL
end

=begin
apt update
apt upgrade
snap install kubectl --classic
wget https://github.com/kubernetes/minikube/releases/download/v1.12.3/minikube-linux-amd64
cp minikube-linux-amd64 /usr/local/bin/minikube
chmod a+x /usr/local/bin/minikube
apt install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
apt install docker-ce
apt install -y bison build-essential cmake flex git libedit-dev \
    libllvm7 llvm-7-dev libclang-7-dev python zlib1g-dev libelf-dev
git clone https://github.com/iovisor/bcc.git
pushd bcc/
git checkout v0.16.0
mkdir build; cd build
cmake
make -j8
make install
popd

minikube start --vm-driver=none
kubectl apply -k /vagrant/manifests/
minikube service wordpress --url
apt install apache-utils
=end
