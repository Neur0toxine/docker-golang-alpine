# Golang Alpine with additional packages & dumb-init

[![Docker Automated build](https://img.shields.io/docker/automated/Neur0toxine/node-alpine-git.svg)](https://hub.docker.com/r/neur0toxine/golang-alpine-dumb-init/)
[![buildx Status](https://github.com/Neur0toxine/docker-golang-alpine-dumb-init/workflows/buildx/badge.svg)](https://github.com/Neur0toxine/docker-golang-alpine-dumb-init/actions?query=workflow%3Abuildx)
[![Lint Dockerfiles](https://github.com/Neur0toxine/docker-golang-alpine-dumb-init/workflows/Lint%20Dockerfiles/badge.svg)](https://github.com/Neur0toxine/docker-golang-alpine-dumb-init/actions?query=workflow%3A%22Lint+Dockerfiles%22)

A minimal Dockerfile based on Go 1.16, 1.17, 1.18 and alpine with dumb-init and some other useful packages.

## What's included

- Go 1.16
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
- go-junit-report
- dumb-init

### Available platforms

These Dockerfiles leverage the new `buildx` functionality and offer the following platforms:

- linux/amd64
- linux/arm64
- linux/arm/v7
- linux/arm/v6
- linux/ppc64le
- linux/s390x

---

Based on solution built by (c) Tim Brust and contributors. Released under the MIT license.
