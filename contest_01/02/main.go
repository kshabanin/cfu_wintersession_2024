package main

import "fmt"

func main() {
    // Количество кислорода, используемое одним человеком за день
    oxygenPerDay := 0.5 // литры

    // Количество дней в году
    daysInYear := 365

    // Количество кислорода, используемое одним человеком за год
    oxygenPerYear := oxygenPerDay * float64(daysInYear)

    fmt.Printf("Количество кислорода, используемое одним человеком за год: %f литров\n", oxygenPerYear)

    // Количество кислорода, выделяемое дубом за год
    oakOxygenPerYear := 20 // литры

    // Количество кислорода, выделяемое тополем за год
    poplarOxygenPerYear := 32 // литры

    // Необходимое количество дубов
    oakNeeded := oxygenPerYear / float64(oakOxygenPerYear)

    // Необходимое количество тополей
    poplarNeeded := oxygenPerYear / float64(poplarOxygenPerYear)

    fmt.Printf("Необходимое количество дубов для обеспечения кислородом одного человека: %f\n", oakNeeded)
    fmt.Printf("Необходимое количество тополей для обеспечения кислородом одного человека: %f\n", poplarNeeded)
}