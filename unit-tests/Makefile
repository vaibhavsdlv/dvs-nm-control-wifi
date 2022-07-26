UNITTESTS_REPORT_DIR ?= .

CXXFLAGS += -std=c++17 -Wall -Wextra -fPIC -g

CXXFLAGS += -I.. -I/data/Qt_5.14/5.14.1/gcc_64/include -I/data/Qt_5.14/5.14.1/gcc_64/include/QtDBus -I/data/Qt_5.14/5.14.1/gcc_64/include/QtCore -I/data/Qt_5.14/5.14.1/gcc_64/mkspecs/linux-g++

LDFLAGS += -L.. -ldvs-nm-control-wifi -Wl,-rpath,/data/Qt_5.14/5.14.1/gcc_64/lib /data/Qt_5.14/5.14.1/gcc_64/lib/libQt5DBus.so /data/Qt_5.14/5.14.1/gcc_64/lib/libQt5Core.so
LDFLAGS += -lgtest_main -lgtest -pthread 

ODIR = obj

_OBJS := test_wificontrol.o


OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(shell mkdir -p obj)

all : tests

clean :
	rm -rf $(TARGET) $(OBJS) tests obj

build: tests

tests : $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run : tests
	LD_LIBRARY_PATH=.. ./tests --gtest_output=xml:$(UNITTESTS_REPORT_DIR)/libwifi_control_nm_results.xml

-include $(OBJFILES:.o=.d)
