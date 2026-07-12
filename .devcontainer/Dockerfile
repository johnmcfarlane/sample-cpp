FROM gcc:16.1.0

RUN apt-get purge --autoremove --yes gcc libgmp-dev make \
  && apt-get update --quiet \
  && apt-get install --no-install-recommends --quiet --yes \
      less \
      lsb-release \
      python3-pip \
      sudo \
      tree \
  && wget https://apt.llvm.org/llvm.sh \
  && chmod +x llvm.sh \
  && ./llvm.sh 23 \
  && rm llvm.sh \
  && apt-get install --no-install-recommends --quiet --yes \
      clang-23 \
      clang-format-23 \
      clang-tidy-23 \
      libc++-23-dev \
      libclang-rt-23-dev \
      lld-23 \
  && apt-get --quiet --yes autoremove \
  && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-23 1 \
  && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-23 1 \
  && update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-23 1 \
  && update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-23 1 \
  && update-alternatives --install /usr/bin/ld ld /usr/bin/lld-23 1

RUN pip install "conan~=2.0" "gcovr~=8.0" "shellcheck-py~=0.11" --break-system-packages --no-cache-dir

ENV BUILD_DIR_PARENT=/root/builds
