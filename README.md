# cpp_learn

## Preparation

### Vagrant

Install vagrant on Mac:
```bash
brew install --cask virtualbox
brew install --cask vagrant
```

Start Ubuntu VM: create and enter a working dir, e.g. `ubuntu`
```bash
vagrant init ubuntu/focal64
vagrant up
```

Setup SSH forward (https://wildlyinaccurate.com/using-ssh-agent-forwarding-with-vagrant/)
* On host machine:
  * Make sure the host can access github
  ```
  ssh -T git@github.com
  ```
  * Add following to `~/.ssh/config`
  ```
  host <VAGRANT_VM_IP>
      ForwardAgent yes
  ```
  * Run command:
  ```
  ssh-add
  ```
* For VM:
  * Add the following to the config block in `Vagrantfile`
  ```
  config.ssh.forward_agent = true
  ```
  * Exit, reload and reconnect VM:
  ```
  exit
  vagrant reload
  vagrant ssh
  ```
