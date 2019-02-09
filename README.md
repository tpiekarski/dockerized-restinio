# dockerized-restinio
*A project for running [RESTinio](https://github.com/Stiffstream/restinio) inside a 
[multi-stage build](https://docs.docker.com/develop/develop-images/multistage-build/) 
[Docker](https://www.docker.com/) container with separated build and runtime stages.*

## Build
```
docker build --target build -t dockerized-restinio/build .
docker build -t dockerized-restinio/runtime . 
```
## Running
```
docker run -d -p 8080:8080 --name restinio dockerized-restinio/runtime
```
