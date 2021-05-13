OBJ = Control.o main.o Record.o ReportGenerator.o ReportGeneratorChange.o ReportGeneratorFarms.o ReportGeneratorHorse.o View.o Map.o

sclr: $(OBJ)
	g++ -o sclr $(OBJ)

Control.o: Control.cc Control.h
	g++ -c Control.cc

main.o: main.cc
	g++ -c main.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

ReportGeneratorChange.o: ReportGeneratorChange.cc ReportGeneratorChange.h
	g++ -c ReportGeneratorChange.cc

ReportGeneratorFarms.o: ReportGeneratorFarms.cc ReportGeneratorFarms.h
	g++ -c ReportGeneratorFarms.cc

ReportGeneratorHorse.o: ReportGeneratorHorse.cc ReportGeneratorHorse.h
	g++ -c ReportGeneratorHorse.cc

View.o: View.cc View.h
	g++ -c View.cc

Map.o: Map.cc Map.h
	g++ -c Map.cc

clean:
	rm -f $(OBJ) sclr
