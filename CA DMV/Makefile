CXX		= g++ -std=c++11
CXXFLAGS	= -g -Wall
OBJS		= Question.o QuestionList.o Test.o Menu.o welcome.o main.o
PROG		= dmv

all:		$(PROG)

$(PROG):	$(OBJS)
		$(CXX) -o $(PROG) $(OBJS)

clean:;		$(RM) $(PROG) core *.o
