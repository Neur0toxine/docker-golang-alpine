# Golang Alpine with additional packages

[![Docker Automated build](https://img.shields.io/docker/automated/neur0toxine/golang-alpine.svg)](https://hub.docker.com/r/neur0toxine/golang-alpine/)
[![buildx Status](https://github.com/Neur0toxine/docker-golang-alpine/workflows/buildx/badge.svg)](https://github.com/Neur0toxine/docker-golang-alpine/actions?query=workflow%3Abuildx)
[![Lint Dockerfiles](https://github.com/Neur0toxine/docker-golang-alpine/workflows/Lint%20Dockerfiles/badge.svg)](https://github.com/Neur0toxine/docker-golang-alpine/actions?query=workflow%3A%22Lint+Dockerfiles%22)

A minimal Dockerfile based on Go 1.16, 1.17, 1.18, 1.19, 1.20, 1.21 and alpine with dumb-init and some other useful packages.

## What's included

- Go 1.16 / 1.17 / 1.18 / 1.19 / 1.20 / 1.21 / 1.22
- images with patched musl to disable `faccessat2` syscall (workaround for CI systems with docker & seccomp filter bug, [see this](https://wiki.alpinelinux.org/wiki/Release_Notes_for_Alpine_3.14.0#faccessat2))
- bash
- make
- git
- gcc
- libc-dev
- jq
- curl
- air
- delve
- gocov
- merge-junit
- gotestsum
- go-junit-report
- dumb-init

### Available platforms

These Dockerfiles leverage the new `buildx` functionality and offer the following platforms:

- linux/amd64
- linux/386
- linux/arm64

---

Based on solution built by (c) Tim Brust and contributors. Released under the MIT license.
