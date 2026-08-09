FROM gcc:16.1.0 AS builder

RUN apt-get purge --autoremove --yes gcc libgmp-dev make
RUN apt-get update --quiet
RUN apt-get install --no-install-recommends --quiet --yes \
      less \
      lsb-release \
      python3-pip \
      sudo \
      tree

RUN bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
RUN apt-get install --no-install-recommends --quiet --yes \
      clang-22 \
      clang-format-22 \
      clang-tidy-22 \
      libc++-22-dev \
      libclang-rt-22-dev \
      lld-22
RUN apt-get --quiet --yes autoremove

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-22 1
RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-22 1
RUN update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-22 1
RUN update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-22 1
RUN update-alternatives --install /usr/bin/ld ld /usr/bin/lld-22 1

RUN pip install "conan~=2.0" "gcovr~=8.0" "shellcheck-py~=0.11" --break-system-packages --no-cache-dir

FROM debian:trixie-20260623-slim
COPY --from=builder /usr /usr
COPY --from=builder /etc /etc
ENV BUILD_DIR_PARENT=/root/builds
