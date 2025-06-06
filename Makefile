CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -I/usr/local/include
LIBS = /usr/local/lib/libTgBot.a -lboost_system -lssl -lcrypto -lpthread

SRC_DIR = ./src
BUILD_DIR = build

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/config.cpp $(SRC_DIR)/command_router.cpp $(SRC_DIR)/keyboard_router.cpp $(SRC_DIR)/bot_app.cpp $(SRC_DIR)/bot_controller.cpp $(SRC_DIR)/logger.cpp $(SRC_DIR)/inline_keyboard_router.cpp
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
TARGET = $(BUILD_DIR)/TGbot

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJ) -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

