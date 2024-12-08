#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

const char *FIRST_NAMES[] = {
    "James", "John", "Robert", "Michael", "William", "David", "Joseph", "Thomas",
    "Charles", "Christopher", "Daniel", "Matthew", "Anthony", "Donald", "Mark",
    "Elizabeth", "Jennifer", "Linda", "Patricia", "Susan", "Jessica", "Sarah",
    "Karen", "Nancy", "Lisa", "Margaret", "Betty", "Sandra", "Ashley", "Dorothy",
    "Kimberly", "Emily", "Donna", "Michelle", "Carol", "Amanda", "Melissa", "Deborah",
    "Stephanie", "Rebecca", "Laura", "Sharon", "Cynthia", "Kathleen", "Helen", "Amy",
    "Shirley", "Angela", "Anna", "Ruth", "Brenda", "Pamela", "Nicole", "Katherine",
    "Virginia", "Catherine", "Christine", "Samantha", "Debra", "Janet", "Carolyn",
    "Rachel", "Heather", "Maria", "Diane", "Emma", "Julie", "Joyce", "Frances",
    "Evelyn", "Joan", "Christina", "Kelly", "Martha", "Lauren", "Victoria", "Judith",
    "Cheryl", "Megan", "Alice", "Ann", "Jean", "Doris", "Andrea", "Marie", "Kathryn",
    "Jacqueline", "Gloria", "Teresa", "Sara", "Janice", "Julia", "Hannah", "Theresa",
    "Grace", "Judy", "Beverly", "Denise", "Marilyn", "Amber", "Danielle", "Brittany",
    "Rose", "Diana", "Abigail", "Natalie", "Jane", "Lori", "Madison", "Tiffany",
    "Kathy", "Tammy", "Kayla", "Suzanne", "Donna", "Lillian", "Lori", "Tina",
    "Michele", "Kristen", "Tracy", "Cindy", "Katie", "Tamara", "Veronica", "Jill",
    "Erin", "Gail", "Alyssa", "Morgan", "Sylvia", "Kelsey", "Kaitlyn", "Holly",
    "Kristina", "Claire", "Peggy", "Carrie", "Haley", "Alexis", "Kara", "Sherry",
    "Patty", "Makayla", "Kylie", "Mackenzie", "Kendra", "Jenna", "Kelsey", "Kaitlin",
    "Katelyn", "Katharine", "Kathleen", "Kathryn", "Kathy", "Katie", "Katrina", "Kayla",
    "Kaylee", "Kayleigh", "Kelli", "Kellie", "Kelly", "Kelsey", "Kendra", "Kiara",
    "Kiera", "Kiersten", "Kim", "Kimberly", "Kira", "Kirsten", "Kirstin", "Krista",
    "Kristen", "Kristin", "Kristina", "Kristine", "Kristy", "Krystal", "Kylie", "Kyra",
    "Lacey", "Lacy", "Lara", "Laura", "Lauren", "Laurie", "Leah", "Leigh", "Leslie",
    "Linda", "Lindsay", "Lindsey", "Lisa", "Liz", "Lori", "Lydia", "Lynn", "Mackenzie",
    "Macy", "Maddie", "Madeline", "Madelyn", "Madison", "Makayla", "Makenzie", "Makenna",
    "Mallory", "Mandy", "Mara", "Marissa", "Marissa", "Marissa", "Marissa", "Marissa"};

const char *LAST_NAMES[] = {
    "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis",
    "Rodriguez", "Martinez", "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson",
    "Taylor", "Moore", "Jackson", "Martin", "Lee", "Thompson", "White", "Harris",
    "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson", "Walker", "Young", "Allen",
    "King", "Wright", "Scott", "Torres", "Nguyen", "Hill", "Flores", "Green",
    "Adams", "Nelson", "Baker", "Hall", "Rivera", "Campbell", "Mitchell", "Carter",
    "Roberts", "Gomez", "Phillips", "Evans", "Turner", "Diaz", "Parker", "Cruz",
    "Edwards", "Collins", "Reyes", "Stewart", "Morris", "Morales", "Murphy", "Cook",
    "Rogers", "Gutierrez", "Ortiz", "Morgan", "Cooper", "Peterson", "Bailey", "Reed",
    "Kelly", "Howard", "Ramos", "Kim", "Cox", "Ward", "Richardson", "Watson",
    "Brooks", "Chavez", "Wood", "James", "Bennett", "Gray", "Mendoza", "Ruiz",
    "Hughes", "Price", "Alvarez", "Castillo", "Sanders", "Patel", "Myers", "Long",
    "Ross", "Foster", "Jimenez", "Powell", "Jenkins", "Perry", "Russell", "Sullivan",
    "Bell", "Coleman", "Butler", "Henderson", "Barnes", "Gonzales", "Fisher", "Vasquez",
    "Simmons", "Romero", "Jordan", "Patterson", "Alexander", "Hamilton", "Graham", "Reynolds",
    "Griffin", "Wallace", "Moreno", "West", "Cole", "Hayes", "Bryant", "Herrera",
    "Gibson", "Ellis", "Tran", "Medina", "Lambert", "Zimmerman", "McDonald", "Vasquez",
    "Castaneda", "Castillo", "Castro", "Cervantes", "Chavez", "Cisneros", "Contreras", "Cortez",
    "Cruz", "Delacruz", "Diaz", "Dominguez", "Duarte", "Estrada", "Fernandez", "Fuentes",
    "Gallegos", "Garcia", "Garza", "Gomez", "Gonzales", "Gonzalez", "Guerrero", "Hernandez",
    "Herrera", "Jimenez", "Juarez", "Lara", "Lopez", "Luna", "Marquez",
    "Martinez", "Medina", "Mendez", "Mendoza", "Mireles", "Molina", "Morales", "Moreno",
    "Munoz", "Murillo", "Navarro", "Nieto", "Nunez", "Ochoa", "Orozco", "Ortega",
    "Ortiz", "Padilla", "Paredes", "Perez", "Ramirez", "Ramos", "Reyes", "Reyna",
    "Rios", "Rivera", "Rodriguez", "Romero", "Rosales", "Rubio", "Ruiz", "Salazar",
    "Salinas", "Sanchez", "Sandoval", "Santana", "Santiago", "Santos", "Serrano", "Silva",
    "Solis", "Soto", "Tellez", "Torres", "Tovar", "Valdez", "Valencia", "Vargas",
    "Vasquez", "Vega", "Velasquez", "Velez", "Villarreal", "Zamora", "Zavala", "Zuniga"};

const char *MERCHANTS[] = {
    "Amazon", "Walmart", "Target", "Costco", "Best Buy", "Starbucks", "McDonalds",
    "Home Depot", "Kroger", "CVS", "Walgreens", "Apple Store", "Uber", "Lyft",
    "Netflix", "Spotify", "Grubhub", "DoorDash", "Instacart", "GameStop",
    "Macy's", "Nordstrom", "Whole Foods", "Trader Joe's", "Petco", "PetSmart",
    "Safeway", "Albertsons", "Ralphs", "Vons", "Pavilions", "Stater Bros",
    "At&T", "Verizon", "T-Mobile", "Sprint", "Comcast", "Charter", "Cox",
    "Bank of America", "Chase", "Wells Fargo", "Citi", "US Bank", "PNC", "TD Bank",
    "American Express", "Capital One", "Discover", "HSBC", "Barclays", "Santander",
    "Fidelity", "Vanguard", "Charles Schwab", "Merrill Lynch", "Edward Jones",
    "State Farm", "Allstate", "Geico", "Progressive", "Farmers", "Nationwide",
    "Liberty Mutual", "USAA", "Aflac", "MetLife", "Prudential", "New York Life",
    "Kaiser Permanente", "UnitedHealthcare", "Anthem", "Cigna", "Humana", "Aetna",
    "Blue Cross Blue Shield", "Medicare", "Medicaid", "Social Security", "Food Stamps",
    "WIC", "Section 8", "Unemployment", "Disability", "Workers Comp", "SSI", "SSDI",
    "EBT", "TANF", "CHIP", "VA", "CalFresh", "CalWORKs", "Medi-Cal", "Covered California",
    "Obamacare", "Affordable Care Act", "Medicare Advantage", "Medicare Supplement",
    "Medicare Part D", "Medicare Part B", "Medicare Part C", "Medicare Part A",
    "Medicare for All", "Single Payer", "Public Option", "Universal Healthcare",
    "Socialized Medicine", "Health Savings Account", "Health Reimbursement Account",
    "Flexible Spending Account", "Health Insurance Marketplace", "Health Insurance Exchange",
    "Health Insurance Premium", "Health Insurance Deductible", "Health Insurance Copay",
    "Health Insurance Coinsurance", "Health Insurance Out-of-Pocket Maximum",
    "Health Insurance Network", "Health Insurance Formulary", "Health Insurance Prior Authorization",
    "Health Insurance Referral", "Health Insurance Preauthorization", "Health Insurance Claim",
    "Health Insurance Explanation of Benefits", "Health Insurance Benefit Summary",
    "Health Insurance Summary of Benefits and Coverage", "Health Insurance Premium Tax Credit"};

const char *CATEGORIES[] = {
    "Retail", "Dining", "Travel", "Entertainment", "Grocery",
    "Gas", "Online Services", "Electronics", "Clothing", "Healthcare",
    "Insurance", "Banking", "Investing", "Real Estate", "Education",
    "Utilities", "Transportation", "Government", "Nonprofit", "Other"};

const char *TRANSACTION_TYPES[] = {
    "Purchase", "Online Purchase", "Contactless Payment", "Mobile Payment",
    "Recurring Charge", "Refund", "Cash Advance", "Balance Transfer",
    "Interest Charge", "Late Fee", "Overdraft Fee", "Foreign Transaction Fee",
    "ATM Fee", "Returned Payment Fee", "Returned Check Fee", "Monthly Fee",
    "Annual Fee", "Membership Fee", "Subscription Fee", "Service Fee",
    "Convenience Fee", "Processing Fee", "Transfer Fee", "Wire Transfer Fee",
    "Deposit", "Withdrawal", "Transfer", "Payment", "Check", "Cash",
    "Credit", "Debit", "Gift Card", "Prepaid Card", "Reloadable Card",
    "Virtual Card", "Digital Wallet", "Cryptocurrency", "Bitcoin", "Ethereum",
    "Litecoin", "Ripple", "Stellar", "Dogecoin", "Cardano", "Polkadot",
    "Chainlink", "Uniswap", "Aave", "Compound", "Maker", "Yearn Finance",
    "SushiSwap", "Synthetix", "Balancer", "Curve Finance", "Ren", "Kyber Network",
    "Bancor", "0x", "Augur", "Gnosis", "Numeraire", "Ocean Protocol", "Orchid",
    "The Graph", "Basic Attention Token", "Decentraland", "Enjin", "Flow",
    "Chiliz", "Audius", "Livepeer", "Origin Protocol", "Render Token", "Rarible"};

const char *CARD_TYPES[] = {
    "Visa", "Mastercard", "American Express", "Discover", "Capital One",
    "Chase Sapphire", "Citi Rewards", "Wells Fargo", "Bank of America", "US Bank",
    "PNC Bank", "TD Bank", "Barclays", "HSBC", "Santander", "Fidelity",
    "Vanguard", "Charles Schwab", "Merrill Lynch", "Edward Jones", "State Farm",
    "Allstate", "Geico", "Progressive", "Farmers", "Nationwide", "Liberty Mutual",
    "USAA", "Aflac", "MetLife", "Prudential", "New York Life", "Kaiser Permanente",
    "UnitedHealthcare", "Anthem", "Cigna", "Humana", "Aetna", "Blue Cross Blue Shield"};

void generate_credit_card_number(char *card_number, const char *card_type)
{
    if (strcmp(card_type, "American Express") == 0)
    {
        sprintf(card_number, "%d%d %d%d%d%d %d%d%d%d %d%d%d%d%d",
                3, (rand() % 2) ? 4 : 7,
                rand() % 10, rand() % 10, rand() % 10, rand() % 10,
                rand() % 10, rand() % 10, rand() % 10, rand() % 10,
                rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10);
    }
    else
    {
        int prefix;
        if (strcmp(card_type, "Visa") == 0)
            prefix = 4;
        else if (strcmp(card_type, "Mastercard") == 0)
            prefix = 5;
        else if (strcmp(card_type, "Discover") == 0)
            prefix = 6;
        else
            prefix = rand() % 9;

        sprintf(card_number, "%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d",
                prefix, rand() % 10, rand() % 10, rand() % 10,
                rand() % 10, rand() % 10, rand() % 10, rand() % 10,
                rand() % 10, rand() % 10, rand() % 10, rand() % 10,
                rand() % 10, rand() % 10, rand() % 10, rand() % 10);
    }
}

void generate_full_name(char *full_name) {
    char first_name[50];
    char last_name[50];
    
    size_t first_names_count = sizeof(FIRST_NAMES) / sizeof(FIRST_NAMES[0]);
    size_t last_names_count = sizeof(LAST_NAMES) / sizeof(LAST_NAMES[0]);
    
    strcpy(first_name, FIRST_NAMES[rand() % first_names_count]);
    strcpy(last_name, LAST_NAMES[rand() % last_names_count]);
    
    sprintf(full_name, "%s %s", first_name, last_name);
}

void generate_email(const char *name, char *email)
{
    char cleaned_name[100];
    int j = 0;

    for (int i = 0; name[i]; i++)
    {
        if (name[i] != ' ')
        {
            cleaned_name[j++] = tolower(name[i]);
        }
    }
    cleaned_name[j] = '\0';

    const char *domains[] = {"gmail.com", "yahoo.com", "hotmail.com", "outlook.com"};
    sprintf(email, "%s@%s", cleaned_name, domains[rand() % 4]);
}

int main()
{
    srand(time(NULL));

    FILE *fp = fopen("enhanced_credit_card_transactions.csv", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "Transaction_ID,Card_Number,Card_Type,Cardholder_Name,Email,Transaction_Category,"
                "Merchant,Transaction_Type,Amount,Currency,Timestamp,Location,Is_Fraud,"
                "Device_Type,Entry_Mode\n");

    for (int i = 0; i < 99999999; i++)
    {
        char card_type[50];
        strcpy(card_type, CARD_TYPES[rand() % (sizeof(CARD_TYPES) / sizeof(CARD_TYPES[0]))]);

        char card_number[25];
        generate_credit_card_number(card_number, card_type);

        char cardholder_name[100];
        generate_full_name(cardholder_name);

        char email[150];
        generate_email(cardholder_name, email);

        char merchant[50];
        strcpy(merchant, MERCHANTS[rand() % (sizeof(MERCHANTS) / sizeof(MERCHANTS[0]))]);

        char transaction_category[50];
        strcpy(transaction_category, CATEGORIES[rand() % (sizeof(CATEGORIES) / sizeof(CATEGORIES[0]))]);

        char transaction_type[50];
        strcpy(transaction_type, TRANSACTION_TYPES[rand() % (sizeof(TRANSACTION_TYPES) / sizeof(TRANSACTION_TYPES[0]))]);

        float amount = (float)(rand() % 150000) / 100.0; // Up to $1500

        time_t timestamp = time(NULL) + (i * 1800); // Transactions 30 minutes apart

        const char *locations[] = {
            "New York (NY)", "Los Angeles (CA)", "Chicago (IL)", "Houston (TX)",
            "Phoenix (AZ)", "Philadelphia (PA)", "San Antonio (TX)", "San Diego (CA)"};
        const char *location = locations[rand() % (sizeof(locations) / sizeof(locations[0]))];

        const char *device_types[] = {"Mobile", "Desktop", "POS Terminal", "ATM"};
        const char *entry_modes[] = {"Chip", "Contactless", "Swipe", "Manual Entry"};

        char device_type[20];
        strcpy(device_type, device_types[rand() % (sizeof(device_types) / sizeof(device_types[0]))]);

        char entry_mode[20];
        strcpy(entry_mode, entry_modes[rand() % (sizeof(entry_modes) / sizeof(entry_modes[0]))]);

        int is_fraud = 0;
        if (amount > 1000)
            is_fraud = (rand() % 3 == 0);
        else if (strcmp(transaction_type, "Cash Advance") == 0)
            is_fraud = (rand() % 5 == 0);
        else if (strcmp(transaction_category, "Electronics") == 0)
            is_fraud = (rand() % 10 == 0); 
        else if (strcmp(location, "New York (NY)") == 0)
            is_fraud = (rand() % 20 == 0);
        else if (strcmp(device_type, "ATM") == 0)
            is_fraud = (rand() % 15 == 0); 
        else if (strcmp(entry_mode, "Manual Entry") == 0)
            is_fraud = (rand() % 8 == 0); 

        fprintf(fp, "%d,%s,%s,%s,%s,%s,%s,%s,%.2f,USD,%ld,%s,%d,%s,%s\n",
                i + 1,                // Transaction ID
                card_number,          // Card Number
                card_type,            // Card Type
                cardholder_name,      // Cardholder Name
                email,                // Email
                transaction_category, // Transaction Category
                merchant,             // Merchant Name
                transaction_type,     // Transaction Type
                amount,               // Transaction Amount
                timestamp,            // Timestamp
                location,             // Location
                is_fraud,             // Fraud Flag
                device_type,          // Device Type
                entry_mode            // Entry Mode
        );
    }

    fclose(fp);

    printf("Enhanced credit card transaction data generated successfully in enhanced_credit_card_transactions.csv\n");

    return 0;
}
