# Rules for building each .o
cs2123p5Driver.o: cs2123p5Driver.c cs2123p5.h
        gcc -g -c cs2123p5Driver.c -o cs2123p5Driver.o
farhadp5.o: farhadp5.c cs2123p5.h
        gcc -g -c farhadp5.c -o farhadp5.o
joshuap5.o: joshuap5.c cs2123p5.h
        gcc -g -c joshuap5.c -o joshuap5.o
lanep5.o: lanep5.c cs2123p5.h
        gcc -g -c lanep5.c -o lanep5.o
# Rule for building the executable
p5: cs2123p5Driver.o farhadp5.o joshuap5.o lanep5.o
        gcc -g -o p5 cs2123p5Driver.o farhadp5.o joshuap5.o lanep5.o
# Special rule to remove the .o files
clean:
        rm -f cs2123p5Driver.o farhadp5.o joshuap5.o lanep5.o
