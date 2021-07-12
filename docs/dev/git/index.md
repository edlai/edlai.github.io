# Git and Build Machine

## Gitlab

you can just apply a free account from `GitHub` or `GitLab`.

## Useful Git commands

- Basic Git commands
```console
$ git log
$ git status
$ git diff <FILENAME>
```

- Get Git log time
```console
git log -1 --format=%cd
```

- Get current Branch
```console
$ git branch | grep \*
```

- Get current Git commit hash
```console
$ git rev-parse HEAD
$ git rev-parse --short HEAD
```

- Get all Git commits since last tag
```console
$ git log $(git describe --tags --abbrev=0)..HEAD --oneline --date=format:'%Y-%m-%d %H:%M:%S' --format="%<(19,trunc)%cd %s (%an) (%h)"
```

- Get Remote URL
```
$ git config --get remote.origin.url
```

## Run Gitlab in Docker

use [docker-gitlab](https://github.com/sameersbn/docker-gitlab) from [sameersbn(Sameer Naik)](https://github.com/sameersbn).

## Git runner

## Azure DevOps

move to Azure from Gitlab
```
```

## Nginx

Add `/etc/nginx/sites-available/gitlab`

```
server {
    listen 88;
    location / {
        proxy_pass        "http://127.0.0.1:10080";
    }
}
```

Restart

```
$ sudo service nginx restart
```
## FTP

- Install vsftpd
- Revised `/etc/vsftpd.conf`

## LIGHTTPD

- Install lighttpd
- Revised `/etc/vsftpd.conf`

## TFTP Server

- Install tftpd-hpa