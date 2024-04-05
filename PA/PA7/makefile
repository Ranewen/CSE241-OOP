JAVAC = javac
JAVA = java
MAIN_CLASS = Main

.PHONY: all clean

all: $(MAIN_CLASS).class

$(MAIN_CLASS).class: $(MAIN_CLASS).java
	$(JAVAC) $<

run: $(MAIN_CLASS).class
	$(JAVA) $(MAIN_CLASS)

clean:
	rm -f *.class