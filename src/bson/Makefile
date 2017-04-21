GCC ?= g++
AR ?= ar

CXXFLAGS ?= --std=c++17

ARFLAGS ?= rcs

OBJDIR = ./obj
LIBDIR = ./lib

OBJECTS = ${OBJDIR}/base64.o ${OBJDIR}/bson.o ${OBJDIR}/hex.o ${OBJDIR}/json.o ${OBJDIR}/parse_number.o ${OBJDIR}/time_support.o ${OBJDIR}/valid.o
LIBS = ${LIBDIR}/libbson.a

all: ${OBJECTS} ${LIBS}

clean:
	rm -Rf ${OBJDIR} ${LIBDIR}

${OBJDIR}:
	if [[ ! -d $@ ]]; then mkdir $@; fi

${LIBDIR}:
	if [[ ! -d $@ ]]; then mkdir $@; fi

${OBJDIR}/%.o: %.cpp ${OBJDIR}
	$(GCC) ${CXXFLAGS} -o $@ -c $<

${LIBDIR}/lib%.a: ${OBJECTS} ${LIBDIR}
	$(AR) ${ARFLAGS} $@ ${OBJECTS}


