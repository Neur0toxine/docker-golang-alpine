FROM golang:1.21-alpine
COPY disable_faccessat2.patch /tmp/disable_faccessat2.patch
RUN set -eux; \
    apk add --no-cache --virtual .build-deps gcc make patch git alpine-sdk coreutils cmake sudo && \
    mkdir -p /var/cache/distfiles && \
    chmod a+w /var/cache/distfiles && \
    git clone --depth 1 --branch "v$(cat /etc/alpine-release)" git://git.alpinelinux.org/aports /tmp/aports && \
    cd /tmp/aports/main/musl && \
    mv /tmp/disable_faccessat2.patch /tmp/aports/main/musl/ && \
    sed -i -E 's/\thandle-aux-at_base.patch/\thandle-aux-at_base.patch\n\tdisable_faccessat2.patch/' APKBUILD && \
    adduser -G abuild -g "Alpine Package Builder" -s /bin/ash -D builder && \
    echo "builder ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    chown -R builder:abuild /tmp/aports && \
    sudo -u builder sh -c 'abuild checksum && abuild-keygen -an && abuild -r' && \
    find /home/builder -type f -name '*.apk' -exec apk add --allow-untrusted --no-cache {} \;; \
    sudo -u builder sh -c 'abuild clean && abuild cleancache' && \
    apk del --no-network .build-deps && \
    deluser builder && \
    rm -rf /home/builder /var/cache/distfiles /tmp/aports
RUN set -eux; \
    apk add --no-cache bash make git gcc libc-dev jq curl dumb-init mailcap && \
    go install github.com/go-delve/delve/cmd/dlv@latest && \
	go install github.com/cosmtrek/air@latest && \
	go install github.com/jstemmer/go-junit-report@latest && \
	go install github.com/axw/gocov/gocov@latest && \
    go install gotest.tools/gotestsum@latest && \
    chmod -R 777 "$GOPATH" && \
    curl -L https://github.com/tobni/merge-junit/releases/download/v0.1.4/merge-junit-v0.1.4-x86_64-unknown-linux-musl.tar.gz | tar -xz && \
    mv ./merge-junit-v0.1.4-x86_64-unknown-linux-musl/merge-junit /usr/bin/merge-junit && \
    rm -rf /merge-junit-v0.1.4-x86_64-unknown-linux-musl
WORKDIR /
ENTRYPOINT ["/usr/bin/dumb-init", "--"]
