; Función para crear una lista de frutas
(define (crear-lista-frutas)
  '())

; Función para agregar una fruta al principio de la lista
(define (agregar-fruta-al-principio lista-frutas fruta)
  (cons fruta lista-frutas))

; Función para agregar una fruta al final de la lista
(define (agregar-fruta-al-final lista-frutas fruta)
  (append lista-frutas (list fruta)))

; Función para eliminar la primera fruta de la lista
(define (eliminar-primera-fruta lista-frutas)
  (if (empty? lista-frutas)
      '()
      (cdr lista-frutas)))

; Función para mostrar la lista de frutas
(define (mostrar-lista-frutas lista-frutas)
  (if (empty? lista-frutas)
      (displayln "La lista de frutas está vacía.")
      (begin
        (displayln "Lista de frutas:")
        (for-each displayln lista-frutas))))

; Ejemplo de uso
(define frutas (crear-lista-frutas))
(define frutas1 (agregar-fruta-al-principio frutas "Manzana"))
(define frutas2 (agregar-fruta-al-principio frutas1 "Banana"))
(define frutas3 (agregar-fruta-al-final frutas2 "Naranja"))
(mostrar-lista-frutas frutas3)
(define frutas4 (eliminar-primera-fruta frutas3))
(mostrar-lista-frutas frutas4)
