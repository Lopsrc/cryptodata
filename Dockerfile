FROM gcc:latest as build

WORKDIR /gtest_build


RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      libgtest-dev \
      cmake \
    && \
    cmake -DCMAKE_BUILD_TYPE=Release /usr/src/gtest && \
    cmake --build .  

ADD ./code /app/code

WORKDIR /app/build

RUN cmake ../code && \
    cmake --build . 

WORKDIR /app/code/test/build  

RUN cmake .. &&\ 
    CTEST_OUTPUT_ON_FAILURE=TRUE cmake --build . 

