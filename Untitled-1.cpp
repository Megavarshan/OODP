#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Structures for modules
struct FarmerData {
    string name;
    string crop;
    double acres;
    double production;
    string language;
};

struct WeatherInfo {
    string region;
    string season;
    string advisory;
};

struct DiseaseInfo {
    string infection;
    string chemical;
    string instructions;
    string reason;
};

// Weather-based crop management database
map<string, WeatherInfo> weatherPatterns = {
    {"Tamil Nadu", {"Sep-Dec", "Rice season. Expect heavy rains, prepare for pest attacks like stem borers."}},
    {"Andhra Pradesh", {"Jun-Sep", "Ideal for maize and pulses. Monitor humidity to prevent fungal growth."}},
    {"Punjab", {"Nov-Apr", "Wheat season. Frost may occur; irrigation recommended after monsoon."}},
    {"West Bengal", {"Sep-Feb", "Pulses and maize season. Moist weather supports fungal infections."}}
};

// Disease database (general)
map<string, DiseaseInfo> diseaseDatabase = {
    {"Rust", {"Propiconazole", "Spray during cool, moist weather.", "Rust spreads in humid conditions."}},
    {"Blast", {"Tricyclazole", "Apply 10-15 days post-transplanting.", "Affects leaves and reduces rice yield."}}
};

// Language-specific messages
map<string, map<string, string>> languageMessages = {
    {"English", {
        {"welcome", "Welcome to the Smart Farming Management System!"},
        {"enter_name", "Please enter your name: "},
        {"enter_crop", "Enter the crop you are growing: "},
        {"acres", "Enter the number of acres: "},
        {"production", "Enter production in tonnes: "},
        {"select_region", "Enter your region: Tamil Nadu, Andhra Pradesh, Punjab, or West Bengal: "},
        {"weather_advice", "Weather Advice: "},
        {"disease_prompt", "Do you see any infection in your crop? (yes/no): "},
        {"infection_name", "Enter the infection name: "},
        {"exit", "Thank you for using the system! Exiting..."}
    }},
    {"Tamil", {
        {"welcome", "விவசாய மேலாண்மை அமைப்பில் வரவேற்கிறோம்!"},
        {"enter_name", "உங்கள் பெயரை பதிவுசெய்க: "},
        {"enter_crop", "நீங்கள் பயிரிடும் பயிரின் பெயரை உள்ளிடவும்: "},
        {"acres", "ஏக்கர் அளவை கூறுங்கள்: "},
        {"production", "தொன்னுகளில் உற்பத்தி அளவைச் சேர்க்கவும்: "},
        {"select_region", "உங்கள் பிராந்தியத்தை தேர்ந்தெடுக்கவும்: தமிழ்நாடு, ஆந்திரப் பிரதேசம், பஞ்சாப், அல்லது மேற்கு வங்கம்: "},
        {"weather_advice", "வானிலை அறிவுரை: "},
        {"disease_prompt", "உங்கள் பயிரில் நோய் இருக்கிறதா? (ஆம்/இல்லை): "},
        {"infection_name", "நோயின் பெயரை உள்ளிடவும்: "},
        {"exit", "நன்றி! வெளியேறுகிறோம்..."}
    }},
    {"Telugu", {
        {"welcome", "స్మార్ట్ వ్యవసాయ నిర్వహణ వ్యవస్థకు స్వాగతం!"},
        {"enter_name", "మీ పేరు నమోదు చేయండి: "},
        {"enter_crop", "మీరు పండిస్తున్న పంటను నమోదు చేయండి: "},
        {"acres", "ఎకరాల సంఖ్యను నమోదు చేయండి: "},
        {"production", "ఉత్పత్తి టన్నులలో నమోదు చేయండి: "},
        {"select_region", "మీ ప్రాంతాన్ని నమోదు చేయండి: తమిళనాడు, ఆంధ్రప్రదేశ్, పంజాబ్, లేదా పశ్చిమ బెంగాల్: "},
        {"weather_advice", "వాతావరణ సలహా: "},
        {"disease_prompt", "మీ పంటలో వ్యాధి ఉందా? (అవును/కాదు): "},
        {"infection_name", "వ్యాధి పేరును నమోదు చేయండి: "},
        {"exit", "ధన్యవాదాలు! బయటకు వెళుతున్నాం..."}
    }}
};

// Display message in selected language
void displayMessage(const string& language, const string& key) {
    cout << languageMessages[language][key] << endl;
}

// Collect farmer details
void collectFarmerData(const string& language) {
    string name, crop, region;
    double acres, production;

    displayMessage(language, "enter_name");
    cin >> name;

    displayMessage(language, "enter_crop");
    cin >> crop;

    displayMessage(language, "acres");
    cin >> acres;

    displayMessage(language, "production");
    cin >> production;

    displayMessage(language, "select_region");
    cin >> region;

    if (weatherPatterns.find(region) != weatherPatterns.end()) {
        cout << languageMessages[language]["weather_advice"] << weatherPatterns[region].advisory << endl;
    }
}

// Diagnose crop diseases
void diagnoseDisease(const string& language) {
    displayMessage(language, "disease_prompt");
    string response;
    cin >> response;

    if (response == "yes" || response == "ஆம்" || response == "అవును") {
        displayMessage(language, "infection_name");
        string infection;
        cin >> infection;

        if (diseaseDatabase.find(infection) != diseaseDatabase.end()) {
            DiseaseInfo info = diseaseDatabase[infection];
            cout << "Chemical: " << info.chemical << endl;
            cout << "Instructions: " << info.instructions << endl;
            cout << "Reason: " << info.reason << endl;
        } else {
            cout << "No matching disease found.\n";
        }
    } else {
        cout << "Great! No infections detected.\n";
    }
}

// Main menu
void menu(const string& language) {
    int choice;
    do {
        displayMessage(language, "welcome");
        cout << "1. Enter Farmer Data\n";
        cout << "2. Diagnose Crop Disease\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                collectFarmerData(language);
                break;
            case 2:
                diagnoseDisease(language);
                break;
            case 3:
                displayMessage(language, "exit");
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);
}

// Main function
int main() {
    cout << "Select your language:\n1. English\n2. Tamil\n3. Telugu\n";
    int langChoice;
    cin >> langChoice;

    string language = (langChoice == 2) ? "Tamil" : (langChoice == 3) ? "Telugu" : "English";

    menu(language);
    return 0;
}