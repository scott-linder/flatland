CXX=clang++
CXX_FLAGS=-std=c++11 -g -Werror -Wall
CXX_LIBS=-lsfml-graphics -lsfml-system -lsfml-window -lBox2D -lentityx

BIN=flatland

IN=src/
OUT=obj/

OBJS=main Flatland Vector2 Factory
OBJS+=CPhysics CPosition CRotation CDrawable
OBJS+=SPhysics SDebug SDraw
OBJS+=ECollision

OBJS:=$(addprefix $(OUT), $(OBJS))
OBJS:=$(addsuffix .o, $(OBJS))

DOCS=docs/

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $(BIN) $(OBJS) $(CXX_LIBS)

$(OUT)%.o: $(IN)%.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

$(OBJS): | $(OUT)

$(OUT):
	[ -d $(OUT) ] || mkdir $(OUT)

docs:
	doxygen Doxyfile

clean:
	-rm -f $(OBJS)
	[ ! -d $(OUT) ] || rmdir $(OUT)
	-rm -f $(BIN)
	-rm -rf $(DOCS)
