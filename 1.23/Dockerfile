FROM golang:1.23-alpine
RUN set -eux; \
    apk add --no-cache bash make git gcc libc-dev jq curl dumb-init mailcap tzdata && \
    go install github.com/go-delve/delve/cmd/dlv@latest && \
	go install github.com/air-verse/air@v1.61.5 && \
	go install github.com/jstemmer/go-junit-report@latest && \
	go install github.com/axw/gocov/gocov@v1.2.1 && \
    go install gotest.tools/gotestsum@v1.12.3 && \
    chmod -R 777 "$GOPATH" && \
    curl -L https://github.com/tobni/merge-junit/releases/download/v0.2.1/merge-junit-v0.2.1-x86_64-unknown-linux-musl.tar.gz | tar -xz && \
    mv ./merge-junit-v0.2.1-x86_64-unknown-linux-musl/merge-junit /usr/bin/merge-junit && \
    rm -rf /merge-junit-v0.2.1-x86_64-unknown-linux-musl
WORKDIR /
ENTRYPOINT ["/usr/bin/dumb-init", "--"]
