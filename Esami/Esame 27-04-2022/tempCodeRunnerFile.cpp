srand(424242);

    AbstractSlotMachine *vec[DIM];

    for (int i = 0; i < DIM; i++)
    {
        if (rand() % 2)
        {
            vec[i] = new ThreeWheelsSlotMachine();
        }
        else
        {
            vec[i] = new TenWheelsSlotMachine();
        }
    }

    for (int i = 0; i < DIM * 100; i++)
    {
        vec[rand() % DIM]->spin();

        if (rand() % 5 == 0)
        {
            vec[rand() % DIM]->reset();
        }
    }