#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/. 
#

###
### Build Stage
###
FROM alpine:latest as build
LABEL description="Build container for dockerized-restinio"
RUN apk update && apk add --no-cache \
    autoconf build-base binutils cmake curl file gcc g++ git http-parser libgcc libtool linux-headers make musl-dev ninja tar unzip wget

RUN cd /tmp \
    && git clone https://github.com/Microsoft/vcpkg.git -n \ 
    && cd vcpkg \
    && git checkout d82f37b4bfc1422d4601fbb63cbd553c925f7014 \
    && ./bootstrap-vcpkg.sh -useSystemBinaries

COPY x64-linux-musl.cmake /tmp/vcpkg/triplets/

RUN VCPKG_FORCE_SYSTEM_BINARIES=1 ./tmp/vcpkg/vcpkg install boost-asio boost-filesystem fmt restinio

COPY ./src /src
WORKDIR /src
RUN mkdir out \
    && cd out \
    && cmake .. -DCMAKE_TOOLCHAIN_FILE=/tmp/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-linux-musl \
    && make

###
### Runtime stage
###
FROM alpine:latest as runtime
LABEL description="Runtime container for dockerized-restinio"

RUN mkdir /usr/local/restinio
COPY --from=build /src/out/dockerized-restinio /usr/local/dockerized-restinio/dockerized-restinio

WORKDIR /usr/local/restinio
CMD ./dockerized-restinio

EXPOSE 8080

