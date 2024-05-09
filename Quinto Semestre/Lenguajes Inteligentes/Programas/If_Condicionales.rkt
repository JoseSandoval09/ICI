

(define gusta-musica-ingles #t)
(define gusta-videojuegos #t)

(define (te-gusta-la-musica-y-los-videojuegos? musica videojuegos)
  (if (and musica videojuegos)
      "Te gusta la música en inglés y los videojuegos."
      (cond
        ((and musica (not videojuegos)) "Te gusta la música en inglés, pero no los videojuegos.")
        ((and (not musica) videojuegos) "No te gusta la música en inglés, pero te gustan los videojuegos.")
        (else "No te gusta la música en inglés ni los videojuegos."))))

(display (te-gusta-la-musica-y-los-videojuegos? gusta-musica-ingles gusta-videojuegos))
(newline)
