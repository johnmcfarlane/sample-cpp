FROM gcc:16.1.0

ARG image_version=trunk

RUN apt-get purge --autoremove --yes gcc libgmp-dev make \
  && apt-get update --quiet \
  && apt-get upgrade --yes \
  && apt-get install --no-install-recommends --quiet --yes \
      ninja-build \
      python3-pip \
      sudo \
  && rm -rf /gcc /build /var/lib/apt/lists/*

RUN pip install "conan==2.24.0" --break-system-packages --no-cache-dir
