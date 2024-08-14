# Variáveis
CXX = g++
CXXFLAGS = -Wall -g
INPUT_FILE = input.txt

# Regra padrão para compilar e executar
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
	./$@ < $(INPUT_FILE)
	rm -f $@

clean:
	rm -f *.o *.out

.PHONY: clean
