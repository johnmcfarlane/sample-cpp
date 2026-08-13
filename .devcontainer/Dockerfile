FROM gcc:16.1.0 AS builder

RUN apt-get purge --autoremove --yes gcc libgmp-dev make
RUN apt-get update --quiet
RUN apt-get install --no-install-recommends --quiet --yes \
      less \
      lsb-release \
      python3-pip \
      sudo \
      tree

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

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-23 1
RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-23 1
RUN update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-23 1
RUN update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-23 1
RUN update-alternatives --install /usr/bin/ld ld /usr/bin/lld-23 1

RUN pip install "conan~=2.0" "gcovr~=8.0" "shellcheck-py~=0.11" --break-system-packages --no-cache-dir

FROM debian:trixie-20260623-slim
COPY --from=builder /usr /usr
COPY --from=builder /etc /etc
ENV BUILD_DIR_PARENT=/root/builds
