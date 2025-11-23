# Poloka

A lightweight and secure blockchain implemented in C/C++. This project demonstrates the core principles of blockchain technology, including block creation, hashing, proof-of-work, and peer-to-peer synchronization.

*Une implémentation de blockchain en C++ pour l'apprentissage et la sécurité.*

## Structure du projet

```
mini-blockchain/
│
├── core/              # Cœur de la blockchain
│   ├── blockchain.h/.cpp   # Structure principale de la blockchain
│   ├── block.h/.cpp        # Définition d'un bloc
│   ├── transaction.h/.cpp  # Définition d'une transaction
│   ├── wallet.h/.cpp       # Portefeuilles et signatures
│   └── pow.h/.cpp          # Preuve de travail
│
├── network/           # Réseau P2P
│   ├── node.h/.cpp        # Logique du nœud (API HTTP)
│   └── peer.h/.cpp        # Découverte et synchronisation des pairs
│
├── explorer/          # Explorateur web
│   ├── app.h/.cpp         # Application web
│   └── templates/         # Templates HTML
│
├── tests/             # Tests unitaires
│   ├── test_blockchain.h/.cpp
│   ├── test_pow.h/.cpp
│   └── test_wallet.h/.cpp
│
├── CMakeLists.txt     # Configuration CMake
├── docker-compose.yml # Configuration Docker
└── README.md          # Ce fichier
```

## Dépendances

### Bibliothèques C++ requises

- **OpenSSL** : Pour la cryptographie (SHA256, ECDSA)
  - Sur Arch Linux: `sudo pacman -S openssl`
  - Sur Ubuntu/Debian: `sudo apt-get install libssl-dev`
  - Sur macOS: `brew install openssl`

- **Bibliothèque HTTP** (à choisir):
  - **cpp-httplib** : Simple, header-only (recommandé pour débuter)
  - **Crow** : Moderne, simple
  - **Drogon** : Plus complexe mais puissant

- **Bibliothèque JSON** (à choisir):
  - **nlohmann/json** : Header-only, très simple (recommandé)
  - **rapidjson** : Rapide mais API plus complexe

### Compilateur

- C++17 ou supérieur
- CMake 3.10 ou supérieur
- GCC 7+ ou Clang 5+

## Compilation

```bash
# Créer le répertoire de build
mkdir build
cd build

# Configurer avec CMake
cmake ..

# Compiler
make

# Ou en mode Release pour optimiser
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## Utilisation

### Lancer un nœud

```bash
# Le nœud écoutera sur le port 3000 par défaut
./build/node
```

### Lancer l'explorateur web

```bash
# L'explorateur écoutera sur le port 8080 par défaut
./build/explorer
```

Ensuite, ouvrez votre navigateur sur `http://localhost:8080`

## Développement

### Notes importantes

1. **Sécurité**: La sécurité est critique pour une blockchain. Assurez-vous de:
   - Valider toutes les entrées
   - Vérifier toutes les signatures
   - Utiliser des fonctions cryptographiques éprouvées (OpenSSL)

2. **Performance**: La preuve de travail peut être très coûteuse en CPU. Pour tester, commencez avec une difficulté faible (2-3).

3. **Réseau**: La synchronisation P2P nécessite une gestion soigneuse des threads et de la concurrence.

## Ressources

- [Bitcoin Whitepaper](https://bitcoin.org/bitcoin.pdf) - Référence fondamentale
- [OpenSSL Documentation](https://www.openssl.org/docs/)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

## Licence

À définir selon vos préférences.
