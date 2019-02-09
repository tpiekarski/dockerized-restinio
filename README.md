# dockerized-restinio
*A lab repository for running RESTinio inside an staged Docker container with separated build and runtime images.*

## Build
```
docker build --target build -t dockerized-restinio/build .
docker build -t dockerized-restinio/runtime . 
```
## Running
```
docker run -d -p 8080:8080 --name restinio dockerized-restinio/runtime
```
