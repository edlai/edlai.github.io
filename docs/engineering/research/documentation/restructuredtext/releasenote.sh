#!/bin/sh

cat RELEASENOTES.rst > ReleaseNoteDraft.rst
sed -i 's/please check CHANGELOG.md for more detail./ /' ReleaseNoteDraft.rst

cat CHANGELOG.md >> ReleaseNoteDraft.rst
