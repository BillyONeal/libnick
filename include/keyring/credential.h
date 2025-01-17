#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <iostream>
#include <string>

namespace Nickvision::Keyring
{
    /**
     * @brief A model of a credential stored in a keyring.
     */
    class Credential
    {
    public:
        /**
         * @brief Constructs a credential.
         * @param id The id of the credential
         * @param name The name of the credential
         * @param uri The uri of the credential (can also be used as a comment for the Credential)
         * @param username The username of the credential
         * @param password The password of the credential
         */
        Credential(int id, const std::string& name, const std::string& uri, const std::string& username, const std::string& password);
        /**
         * @brief Constructs a credential.
         * @param name The name of the credential
         * @param uri The uri of the credential
         * @param username The username of the credential
         * @param password The password of the credential
         */
        Credential(const std::string& name, const std::string& uri, const std::string& username, const std::string& password);
        /**
         * @brief Gets the id of the credential
         * @return The id of the credential
         */
        int getId() const;
        /**
         * @brief Gets the name of the credential
         * @return The name of the credential
         */
        const std::string& getName() const;
        /**
         * @brief Sets the name of the credential
         * @param name The name of the credential
         */
        void setName(const std::string& name);
        /**
         * @brief Gets the uri of the credential (can also be used as a comment for the Credential)
         * @return The uri of the credential
         */
        const std::string& getUri() const;
        /**
         * @brief Sets the uri of the credential (can also be used as a comment for the Credential)
         * @param uri The uri of the credential
         */
        void setUri(const std::string& uri);
        /**
         * @brief Gets the username of the credential
         * @return The username of the credential
         */
        const std::string& getUsername() const;
        /**
         * @brief Sets the username of the credential
         * @param username The username of the credential
         */
        void setUsername(const std::string& username);
        /**
         * @brief Gets the password of the credential
         * @return The password of the credential
         */
        const std::string& getPassword() const;
        /**
         * @brief Sets the password of the credential
         * @param password The password of the credential
         */
        void setPassword(const std::string& password);
        /**
         * @brief Compares Credential objects via < operator
         * @param compare The Credential object to compare too
         * @return True if this < compare
         */
        bool operator<(const Credential& compare) const;
        /**
         * @brief Compares Credential objects via > operator
         * @param compare The Credential object to compare too
         * @return True if this > compare
         */
        bool operator>(const Credential& compare) const;
        /**
         * @brief Compares Credential objects via == operator
         * @param compare The Credential object to compare too
         * @return True if this == compare
         */
        bool operator==(const Credential& compare) const;
        /**
         * @brief Compares Credential objects via != operator
         * @param compare The Credential object to compare too
         * @return True if this != compare
         */
        bool operator!=(const Credential& compare) const;
        /**
         * @brief Outputs the Credential object
         */
        friend std::ostream& operator<<(std::ostream& os, const Credential& credential);

    private:
        int m_id;
        std::string m_name;
        std::string m_uri;
        std::string m_username;
        std::string m_password;
    };
}

#endif //CREDENTIAL_H