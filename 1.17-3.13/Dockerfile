FROM golang:1.17-alpine3.13
RUN set -eux; \
    apk add --no-cache bash make git gcc libc-dev jq curl dumb-init && \
    go install github.com/go-delve/delve/cmd/dlv@latest && \
	go install github.com/cosmtrek/air@latest && \
	go install github.com/jstemmer/go-junit-report@latest && \
	go install github.com/axw/gocov/gocov@latest && \
    chmod -R 777 "$GOPATH"
WORKDIR /
ENTRYPOINT ["/usr/bin/dumb-init", "--"]
