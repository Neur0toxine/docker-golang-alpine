FROM golang:1.16-alpine
RUN set -eux; \
    apk add --no-cache bash make git gcc libc-dev jq curl dumb-init && \
    cd /tmp && \
    git clone https://github.com/go-delve/delve && \
    cd delve && \
    go install github.com/go-delve/delve/cmd/dlv && \
    cd / && \
    go install github.com/cosmtrek/air@latest && \
    rm -rf delve && \
    chmod -R 777 /go
WORKDIR /
ENTRYPOINT ["/usr/bin/dumb-init", "--"]
