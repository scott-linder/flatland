CXX=clang++
CXX_FLAGS=-std=c++11 -g -Werror -Wall
CXX_LIBS=-lsfml-graphics -lsfml-system -lsfml-window -lBox2D -lentityx

BIN=asteroids

IN=src/
OUT=obj/

OBJS=main Asteroids Vector2
OBJS+=CPhysics CPosition CRotation
OBJS+=SPhysics SDebug SDraw
OBJS+=ECollision

OBJS:=$(addprefix $(OUT), $(OBJS))
OBJS:=$(addsuffix .o, $(OBJS))

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $(BIN) $(OBJS) $(CXX_LIBS)

$(OUT)%.o: $(IN)%.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

$(OBJS): | $(OUT)

$(OUT):
	[ -d $(OUT) ] || mkdir $(OUT)

clean:
	-rm -f $(OBJS)
	[ ! -d $(OUT) ] || rmdir $(OUT)
	-rm -f $(BIN)
