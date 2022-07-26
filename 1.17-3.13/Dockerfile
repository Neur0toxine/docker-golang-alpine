FROM golang:1.17-alpine3.13
WORKDIR /
RUN apk add --no-cache bash make git gcc libc-dev jq curl dumb-init
RUN cd /tmp && \
    git clone https://github.com/go-delve/delve && \
    cd delve && \
    go install github.com/go-delve/delve/cmd/dlv && \
    cd .. && \
    curl -sSfL https://raw.githubusercontent.com/cosmtrek/air/master/install.sh | sh -s -- -b $(go env GOPATH)/bin && \
    rm -rf delve && \
    chmod -R 777 /go
ENTRYPOINT ["/usr/bin/dumb-init", "--"]
