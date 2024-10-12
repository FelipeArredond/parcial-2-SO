CXX = g++
OMP_PREFIX = $(shell brew --prefix libomp)
JPEG_PREFIX = $(shell brew --prefix jpeg)
OPENCV_PREFIX = $(shell brew --prefix opencv)
CXXFLAGS = -std=c++17 -Wall -Xpreprocessor -fopenmp -I$(OMP_PREFIX)/include -I$(JPEG_PREFIX)/include -I$(OPENCV_PREFIX)/include/opencv4
LDFLAGS = -L$(OMP_PREFIX)/lib -L$(JPEG_PREFIX)/lib -L$(OPENCV_PREFIX)/lib -lomp -ljpeg -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_objdetect

SRCS = main.cpp jpeg_manager.cpp procesador_imagen.cpp opencv_manager.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = programa_jpeg

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) imagen_ejemplo.jpg

install-deps:
	@echo "Instalando dependencias..."
	@chmod +x install_dependencies.sh
	@./install_dependencies.sh

.PHONY: all clean run install-deps