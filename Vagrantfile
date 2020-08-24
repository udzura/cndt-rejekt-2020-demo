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
    6  sudo apt update
    7  sudo apt upgrade
    9  sudo snap install kubectl --classic
   29  wget https://github.com/kubernetes/minikube/releases/download/v1.12.3/minikube-linux-amd64
   30  sudo cp minikube-linux-amd64 /usr/local/bin/minikube
   32  sudo chmod a+x /usr/local/bin/minikube
sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -


=end
