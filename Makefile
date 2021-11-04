MANYLINUX2010_DOCKERFILE=Dockerfile.cp310.manylinux2010
DOCKER_NAME=edfre-pydnp3
DOCKER_NAME_MANYLINUX=edfre-pydnp3-manylinux2010

build-container:
	docker build . -f Dockerfile.alpine -t $(DOCKER_NAME)

run: build-container
	-docker rm $(DOCKER_NAME)
	docker run --name $(DOCKER_NAME) $(DOCKER_NAME)

sh:
	docker exec -it $(DOCKER_NAME) sh

manylinux2010-build-container:
	docker build . -f $(MANYLINUX2010_DOCKERFILE) -t $(DOCKER_NAME_MANYLINUX)

manylinux2010-run: manylinux2010-build-container
	-docker rm $(DOCKER_NAME_MANYLINUX)
	docker run --name $(DOCKER_NAME_MANYLINUX) $(DOCKER_NAME_MANYLINUX)

manylinux2010-sh:
	docker exec -it $(DOCKER_NAME_MANYLINUX) sh

manylinux2010-build-wheel: manylinux2010-run

manylinux2010-copy-wheel-to-host:
	docker cp $(DOCKER_NAME_MANYLINUX):/usr/src/app/wheels/ .tmp-wheels-from-manylinux2010
	cp .tmp-wheels-from-manylinux2010/pydnp3-*.whl wheel
	rm -rf .tmp-wheels-from-manylinux2010

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

local-setup:
	pip install wheel

local-build-wheel:
	pip wheel -w wheel -e .
