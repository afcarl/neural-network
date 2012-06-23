CXX		=	g++
CXXFLAGS	=	-W -Wall
LFLAGS		=	
TARGET		=	libneural_network.a
SOURCES		=	mlperceptron.cpp \
				perceptron.cpp \
				neural_network_exception.cpp \
				seed_initializer.cpp \
				activation_function.cpp

OBJECTS		=	$(SOURCES:.cpp=.o)

$(TARGET):	$(OBJECTS)
		ar r $(TARGET) $(OBJECTS)
		ranlib $(TARGET)

all:		$(TARGET)

clean:
		rm -f $(OBJECTS)

mrproper:	clean
		rm $(TARGET)
