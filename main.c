#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t acumulador;
    uint8_t registradores[16];
    uint8_t carry;
    uint16_t pc; // Program Counter de 12 bits
    uint8_t rom[4096] // 4096 endereços de armazenamento porque 2 elevado a 12 bits do PC resulta em 4096
} CPU;

void cpu_inicializar(CPU *cpu);
void cpu_somar(CPU *cpu, uint8_t valor);
void cpu_imprimir(const CPU *cpu);

void cpu_carregar_programa(CPU *cpu);
uint8_t cpu_buscar_instrucao(CPU *cpu);


int main(void){
    // processo Fetch-Decode-Execute
    CPU cpu;
    cpu_inicializar(&cpu);
    cpu_somar(&cpu, 0x0A);
    cpu_imprimir(&cpu);
    return 0;
}


void cpu_inicializar(CPU *cpu){
    for (int i = 0; i < 16; i++){
        cpu->registradores[i] = 0;
    }
    cpu->acumulador = 0;
    cpu->carry = 0;
    cpu->pc = 0;
}

void cpu_somar(CPU *cpu, uint8_t valor){
    uint16_t resultado = valor + cpu->acumulador;
    cpu->carry = resultado > 0x0F;
    cpu->acumulador = resultado & 0x0F;
}

void cpu_imprimir(const CPU *cpu){
    printf("Acumulador: %X\nCarry: %X\n", cpu->acumulador, cpu->carry);
}
