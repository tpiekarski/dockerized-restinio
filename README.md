dockerized-restinio
---
[![Build Status](https://api.travis-ci.org/tpiekarski/dockerized-restinio.svg?branch=master)](https://travis-ci.org/tpiekarski/dockerized-restinio)

*A project for running [RESTinio](https://github.com/Stiffstream/restinio), 
an embedded and lightweight HTTP/Websocket server written in C++14 inside a 
[multi-stage build](https://docs.docker.com/develop/develop-images/multistage-build/) 
[Docker](https://www.docker.com/) container with separated build and runtime stages.*

## Build dockerized-restinio/build 
```
docker build --target build -t dockerized-restinio/build . 
```

## Build dockerized-restinio/runtime
```
docker build -t dockerized-restinio/runtime .
```

## Run dockerized RESTinio
```
docker run -d -p 8080:8080 --name restinio dockerized-restinio/runtime
```

## Reach RESTinio
```
curl -vX GET localhost:8080
```