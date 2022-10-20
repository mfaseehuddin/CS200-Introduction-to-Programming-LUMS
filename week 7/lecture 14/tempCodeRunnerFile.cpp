~Connection()
    {
        if (instance != NULL)
        {
            delete instance;
            instance = NULL;
            cout << "Connection destroyed" << endl;
            return;
        }

        cout << "There is no instance to destroy" << endl;
    }