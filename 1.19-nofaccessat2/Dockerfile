FROM golang:1.19-alpine
COPY disable_faccessat2.patch /tmp/disable_faccessat2.patch
RUN set -eux; \
    apk add --no-cache --virtual .build-deps gcc make patch git alpine-sdk && \
    apk add --no-cache --virtual .build-deps2 -X http://dl-cdn.alpinelinux.org/alpine/edge/testing gosu && \
    mkdir -p /var/cache/distfiles && \
    chmod a+w /var/cache/distfiles && \
    git clone --depth 1 --branch "v$(cat /etc/alpine-release)" git://git.alpinelinux.org/aports /tmp/aports && \
    cd /tmp/aports/main/musl && \
    mv /tmp/disable_faccessat2.patch /tmp/aports/main/musl/ && \
    sed -i -E 's/\thandle-aux-at_base.patch/\thandle-aux-at_base.patch\n\tdisable_faccessat2.patch/' APKBUILD && \
    adduser -S builder -G abuild && \
    chown -R builder:abuild /tmp/aports && \
    gosu builder:abuild sh -c 'abuild checksum && abuild-keygen -an && abuild -r' && \
    find /home/builder -iname './*.apk' -exec apk add --allow-untrusted --no-cache {} \;; \
    gosu builder:abuild sh -c 'abuild clean && abuild cleancache' && \
    apk del --no-network .build-deps && \
    apk del --no-network .build-deps2 && \
    deluser builder && \
    rm -rf /home/builder
RUN set -eux; \
    apk add --no-cache bash make git gcc libc-dev jq curl dumb-init && \
    go install github.com/go-delve/delve/cmd/dlv@latest && \
	go install github.com/cosmtrek/air@latest && \
	go install github.com/jstemmer/go-junit-report@latest && \
	go install github.com/axw/gocov/gocov@latest && \
    chmod -R 777 "$GOPATH"
WORKDIR /
ENTRYPOINT ["/usr/bin/dumb-init", "--"]
