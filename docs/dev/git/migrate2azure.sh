#!/bin/bash

###############################################################################
# Migrate Repo to Azure DevOps from GitLab
# Notice:
#   - run this script to root folder of your SDK
#   - apply a token from Azure DevOps before you do so.
#     (don't do migration via ssh, it will cause "unsupported compression issue"
###############################################################################

# 1). check code (an example as following)
# git clone -bare http://172.17.2.205:10080/root/covr-1100.git --branch develop covr_1100
# cd covr_1100

# 2). grab all branches
for branch in `git branch -a | grep remotes | grep -v HEAD | grep -v master `; do
   git branch --track ${branch#remotes/origin/} $branch
done

# 3). confirm that all branches are here
git branch -a

# 4). push to azure devOps, issue the token if it asks you the password (an example as following)
# git push --mirror https://wpspd-rd-covr1100@dev.azure.com/wpspd-rd-covr1100/covr_1100/_git/covr_1100
