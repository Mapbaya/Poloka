# TODO: Dockerfile pour la blockchain
# Image de base avec compilateur C++
FROM gcc:latest

# TODO: Installer les dépendances système
RUN apt-get update && apt-get install -y \
    cmake \
    libssl-dev \
    curl \
    && rm -rf /var/lib/apt/lists/*

# TODO: Créer le répertoire de travail
WORKDIR /app

# TODO: Copier les fichiers source
COPY . .

# TODO: Créer le répertoire de build
RUN mkdir build && cd build

# TODO: Configurer et compiler avec CMake
WORKDIR /app/build
RUN cmake .. && make

# TODO: Exposer les ports
# Port du nœud
EXPOSE 3000
# Port de l'explorateur
EXPOSE 8080

# TODO: Commande par défaut (peut être overridée dans docker-compose)
CMD ["./node"]

