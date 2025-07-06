#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void print_code_lines(string code_lines[], int total_code_lines)
{
    for (int i = 0; i < total_code_lines; i++)
    {
        cout << i << " : " << code_lines[i] << endl;
    }
}
void skipSpaces(int &i, string &line)
{
    bool skipped_spaces = false;
    while (line[i] == ' ')
    {
        skipped_spaces = true;
        i++;
    }
    if (skipped_spaces)
    {
        cout << "skipped spaces" << endl;
    }
}
void receiveAlNum(int &i, string &line, string &alnum_receiver)
{
    while (isalnum(line[i]))
    {
        alnum_receiver.push_back(line[i]);
        i++;
    }
    cout << alnum_receiver << endl;
}

struct Tag
{
    string tag_name;
    map<string, string> attributes;
    int op_line_num = -1;
    int closing_line_num = -1;
};

void createTag(int &i, string &line, string code_lines[], int &index, int &total_code_lines)
{
    Tag new_tag;

    // take the tag_name
    cout << "received tagname : ";
    receiveAlNum(i, line, (new_tag.tag_name));

    new_tag.op_line_num = index;
    // now we are taking the attributes in the map
    // we'll run the loop till we get all the attributes
    // That is one loop gets one attribute
    string key;
    string value;
    while (line[i] != '>')
    {
        // skip the spaces
        skipSpaces(i, line);

        // attribute = {key : value}

        // taking the KEY for the attribute
        cout << "received Key for Attribute: ";
        receiveAlNum(i, line, key);

        //  skipping all the spaces, = and inverted commas(")
        while (!isalnum(line[i]))
        {
            i++;
        }

        // taking the VALUE for the attribute
        cout << "received Value for Attribute: ";
        receiveAlNum(i, line, value);

        (new_tag.attributes).insert(key, value);
        // empty the key for the next attribute
        key = "";
        value = "";
    }
    // now we need to find the closing line number of the tag
    string close_tag = "</" + new_tag.tag_name + ">";
    for (int k = index; k < total_code_lines; k++)
    {
        if (close_tag == code_lines[k])
        {
            new_tag.closing_line_num = k;
            code_lines[k] = "";
        }
        else
        {
            continue;
        }
    }
}

int main()
{
    // t1 -> no. of lines of HRML code
    // t2 -> no. of lines queries
    int t1, t2;
    cin >> t1;
    cin >> t2;
    int total_code_lines = t1;
    string code_lines[t1];
    string query_lines[t2];
    int line_no = 0;
    // take all the code lines at once
    while (t1--)
    {

        /* bool taking_tag = false;
        bool closing_tag = false; */
        getline(cin, code_lines[line_no]);
        line_no++;
        // traverse the code line
    }
    print_code_lines(code_lines, total_code_lines);

    for (int index = 0; index < line_no; index++)
    {

        // now we traverse the code_lines
        // line shouldn't be empty
        if (code_lines[index].length() > 0)
        {

            int i = 0;
            while (i < code_lines[index].length())
            {
                string line = code_lines[i];
                if (line[0] == '<')
                {
                    // we move to the next alnum value which will be tagname
                    // loop needs to manually increment int i
                    i++;

                    // skip all the spaces , for eg  [  <     tag1 value = "value" ..... ]
                    skipSpaces(i, line);
                }

                // now we create the tag from the line received
                createTag(i, line, code_lines, index, total_code_lines);
            }
        }
    }

    while (t2--)
    {
        // execute the queries
    }
}
