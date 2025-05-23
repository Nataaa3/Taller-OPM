# Taller-OPM
# 🧵 Taller OpenMP - Sistemas Operativos

**Autor:** Natalia Ramírez Romero  
**Fecha:** 22 de mayo de 2025  
**Materia:** Sistemas Operativos  
**Universidad:** Pontificia Universidad Javeriana  

## 📌 Descripción

Este repositorio contiene el desarrollo de un laboratorio sobre el uso de **OpenMP** para la paralelización de bucles en C.  
El objetivo es observar el comportamiento de variables privadas y compartidas en regiones paralelas, utilizando múltiples hilos para ejecutar un ciclo `for`.

---

## 📁 Archivos

- `omplab_ramirez.c`: Código fuente con comentarios explicativos y conclusiones al final.
- `README.md`: Documento descriptivo con instrucciones y contexto del proyecto.

---

## ⚙️ Instrucciones de compilación y ejecución

Asegúrate de tener `gcc` con soporte para OpenMP instalado. Luego, compila y ejecuta el programa con los siguientes comandos:

```bash
gcc -fopenmp omplab_ramirez.c -o ejecutable
./ejecutable 4   # Puedes cambiar el número 4 por la cantidad de hilos que desees usar
