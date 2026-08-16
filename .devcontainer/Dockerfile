# build from an image with recent GCC
FROM gcc:16.1.0 AS builder

# install supporting system packages
RUN apt-get purge --autoremove --yes gcc libgmp-dev make
RUN apt-get update --quiet
RUN apt-get install --no-install-recommends --quiet --yes \
      curl \
      less \
      lsb-release \
      python3-pip \
      sudo \
      tar \
      tree \
      unzip \
      zip

# install recent LLVM toolchain and tools
RUN wget https://apt.llvm.org/llvm.sh
RUN chmod +x llvm.sh
RUN ./llvm.sh 23
RUN apt-get install --no-install-recommends --quiet --yes \
      clang-23 \
      clang-format-23 \
      clang-tidy-23 \
      libc++-23-dev \
      libclang-rt-23-dev \
      lld-23
RUN apt-get --quiet --yes autoremove

# create version-independent LLVM commands
RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-23 1
RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-23 1
RUN update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-23 1
RUN update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-23 1
RUN update-alternatives --install /usr/bin/ld ld /usr/bin/lld-23 1

# install Python system packages
RUN pip install "conan~=2.0" "gcovr~=8.0" "shellcheck-py~=0.11" --break-system-packages --no-cache-dir

# copy to a minimal image
FROM debian:trixie-20260623-slim
COPY --from=builder /usr /usr
COPY --from=builder /etc /etc
ENV BUILD_DIR_PARENT=/root/builds

WORKDIR /root
RUN git clone https://github.com/Microsoft/vcpkg.git
WORKDIR /root/vcpkg
RUN ./bootstrap-vcpkg.sh
# RUN ./vcpkg integrate install
ENV VCPKG_ROOT=/root/vcpkg
ENV PATH="$VCPKG_ROOT:$PATH"
