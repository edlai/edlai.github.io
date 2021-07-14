#!/bin/bash

###############################################################################
# Migrate Repo from GitLab to Azure DevOps
# Notice:
#   - run this script to root folder of your SDK
#   - apply a token from Azure DevOps before you do so.
#     (don't do migration via ssh connection, it will cause "unsupported compression issue"
###############################################################################

# 1). check code (an example as following)
# git clone -bare ${OLD_REPO} old_repo
# cd old_repo

# 2). grab all branches
for branch in `git branch -a | grep remotes | grep -v HEAD | grep -v master `; do
   git branch --track ${branch#remotes/origin/} $branch
done

# 3). confirm that all branches are here
git branch -a

# 4). push to azure devOps, issue the token if it asks you the password (an example as following)
# git push --mirror ${NEW_REPO}
