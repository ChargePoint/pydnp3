DOCKER_NAME=edfre-pydnp3

build-container:
	docker build . -f Dockerfile.alpine -t edfre-pydnp3

run: build-container
	-docker rm edfre-pydnp3
	docker run --name edfre-pydnp3 edfre-pydnp3

build-docs: run

copy-docs-to-host:
	rm -rf docs
	docker cp $(DOCKER_NAME):/usr/src/app/docs/html/ docs/
	rm -rf docs-rst
	docker cp $(DOCKER_NAME):/usr/src/app/docs/rst/ docs-rst/

copy-wheel-to-host:
	docker cp $(DOCKER_NAME):/usr/src/app/wheels/ .tmp-wheels-from-alpine
	rename linux alpine-linux .tmp-wheels-from-alpine/pydnp3-*.whl
	cp .tmp-wheels-from-alpine/pydnp3-*.whl wheel
	rm -rf .tmp-wheels-from-alpine
