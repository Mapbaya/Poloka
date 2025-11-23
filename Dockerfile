FROM gcc:latest

RUN apt-get update && apt-get install -y \
    cmake \
    libssl-dev \
    curl \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN mkdir build && cd build

WORKDIR /app/build
RUN cmake .. && make

EXPOSE 3000
EXPOSE 8080

CMD ["./node"]

