# Chemins
SRC_DIR = ../code/src
INC_DIR = ../code/includes

# Nom de l'exécutable
TARGET = wolf3d

# Récupère tous les fichiers .cpp dans SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Options de compilation
CXX = g++
CXXFLAGS = -std=c++11 -I$(INC_DIR) `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

# Règle par défaut
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

# Nettoyage
clean:
	rm -f $(TARGET)