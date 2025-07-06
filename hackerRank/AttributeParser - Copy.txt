#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define SAFE_PRINT(x)             \
    if (line_count++ < MAX_LINES) \
        // cout << x << endl;
int MAX_LINES = 1000; // Set your output line limit
int line_count = 0;

struct Tag
{
    string tag_name;
    map<string, string> attributes;
    int op_line_num = -1;
    int closing_line_num = -1;
};

/*
the order in which these are defined (not declared)
is important as some functions are calling others too
for convenience I have declaration them in same order as their defined
*/

void fn_print_Tags(vector<Tag> &vec_Tags);  // made only for debugging
void fn_skipNonAlNum(int &i, string &line); // skips any non alpha numeric value
void skipSpaces(int &i, string &line);
string receiveAlNum(int &i, string &line, string &alnum_receiver);
Tag createTag(int &i, string &line, string code_lines[], int &index, int &total_code_lines);
int fn_get_close_line_num(string code_lines[], int &index, int &total_code_lines, string &close_tag, Tag &new_tag);
int fn_get_next(int &index, int &closing_line_num ,int &op_line_num );
bool fn_check_key_exists(vector<Tag> &vec_Tags, string current_tag_name);
// bool fn_valid_child(vector<Tag> &vec_Tags, string &current_tag_name,string &next_tag_name);

void fn_print_Tags(vector<Tag> &vec_Tags)
{
    // cout << "---fn_print_Tags() STARTED---\n";

    // structs received

    for (int i = 0; i < (int)vec_Tags.size(); i++)
    {
        // print the tagname

        // cout << endl << i << " : TagName : " << vec_Tags[i].tag_name << endl;

        // print its attributes

        // cout << "Attributes :\n";
        map<string, string> tag_attributes = (vec_Tags[i].attributes);
        // cout << "{ ";
        for (auto it = tag_attributes.begin(); it != tag_attributes.end(); it++)
        {
            // cout << it->first << " : " << it->second << " , ";
        }
        // cout << " }\n";

        // print its opening and closing

        // cout << "op_line_num :" << vec_Tags[i].op_line_num << endl;
        // cout << "close_line_num :" << vec_Tags[i].closing_line_num << endl;
    }
    // cout << "---fn_print_Tags() ENDED---\n";
}

void fn_skipNonAlNum(int &i, string &line)
{
    // cout << "---fn_skipAlNum() STARTED---\n";
    while (i < (int)line.length() && !isalnum(line[i]))
    {
        i++;
        // cout << " i : " << i << " Line[i] : " << line[i] << endl;
    }
    // cout << "---fn_skipAlNum() ENDED---\n";
}

void skipSpaces(int &i, string &line)
{
    // cout << "---skipSpaces() STARTED---\n";
    bool skipped_spaces = false;
    while (line[i] == ' ')
    {
        skipped_spaces = true;
        i++;
        // cout << " i : " << i << " Line[i-1] : space" << endl;
    }
    if (skipped_spaces)
    {
        // cout << "skipped spaces" << endl;
    }
    // cout << "---skipSpaces() ENDED---\n";
}

string receiveAlNum(int &i, string &line, string &alnum_receiver)
{
    alnum_receiver = "";
    // cout << "---receiveAlNum() started---\n";
    while (isalnum(line[i]))
    {
        alnum_receiver.push_back(line[i]);
        i++;
        // cout << " i : " << i << " Line[i] : " << line[i] << endl;
    }
    // cout << "---receiveAlNum() ended---\n";
    return alnum_receiver;
}

Tag createTag(int &i, string &line, string code_lines[], int &index, int &total_code_lines)
{
    // cout << "---createTag() STARTED---\n";
    Tag new_tag;

    // take the tag_name

    new_tag.tag_name = receiveAlNum(i, line, (new_tag.tag_name));

    // cout << "received tagname : " << new_tag.tag_name << endl;
    // cout << "--------" << endl;

    new_tag.op_line_num = index;

    // now we are taking the attributes in the map

    // we'll run the loop till we get all the attributes

    // That is one loop gets one attribute

    string key;
    string value;
    while ((i < (int)line.length()))
    {
        // cout << "----inner loop----\n";
        // cout << "i at the START of INNER LOOP : " << i << endl;

        // skip the spaces

        skipSpaces(i, line);

        // skip other shit too ???

        // attribute = {key : value}

        // taking the KEY for the attribute

        key = receiveAlNum(i, line, key);
        // cout << "received Key for Attribute: " << key << endl;

        //  skipping all the non alphannumeric values( to remove = , " , spaces)

        fn_skipNonAlNum(i, line);

        // taking the VALUE for the attribute

        value = receiveAlNum(i, line, value);
        // cout << "received Value for Attribute: " << value << endl;

        // only skipping the inverted commas and the spaces doesn't work

        /* while (!isalnum(line[i]) && (line[i] != '>') )
        {
            i++;
            // cout << " i : "<< i << " Line[i] : " << line[i] <<endl ;
            } */

        // so we are skiping '>' as well

        fn_skipNonAlNum(i, line);

        (new_tag.attributes).insert({key, value});

        // empty the key for the next attribute

        key = "";
        value = "";
    }

    // now we need to find the closing line number of the tag
    // Note : we must remove spaces and extract alnum in case input line is shit

    string close_tag = "</" + new_tag.tag_name + ">";
    new_tag.closing_line_num = fn_get_close_line_num(code_lines, index, total_code_lines, close_tag, new_tag);
    // cout << "---createTag() ENDED---\n";
    return new_tag;
}

int fn_get_close_line_num(string code_lines[], int &index, int &total_code_lines, string &close_tag, Tag &new_tag)
{
    for (int k = index; k < total_code_lines; k++)
    {
        int i = 0;
        string cmp_str = "";

        // this is the shitty job - very necessary

        if (code_lines[k][i] == ' ')
        {
            skipSpaces(i, code_lines[k]);

            while (i < (int)code_lines[k].length())
            {
                cmp_str.push_back(code_lines[k][i]);

                i++;
            }
        }
        else
        {
            cmp_str = code_lines[k];
        }
        //  cout << endl << "Line Index : " << k << " Close Tag Checked String : " << cmp_str << " " << cmp_str.length() << endl;

        if (close_tag == cmp_str)
        {
            code_lines[k] = "";
            return k;
        }
        else
        {
            continue;
        }
    }
    return 0 ;
}

string fn_check_key_exists(vector<Tag> &vec_Tags, string &current_tag_name, string &query_attribute_key)
{
    string              query_attribute_value;
    bool                tag_exists        = false;
    bool                tag_has_attribute = false;
    map<string, string> tag_attributes;
    for (int i = 0; i < (int)vec_Tags.size(); i++)
    {

        if (current_tag_name == vec_Tags[i].tag_name)
        {
            tag_exists = true;
            tag_attributes = vec_Tags[i].attributes;

            for (auto it = tag_attributes.begin(); it != tag_attributes.end(); it++)
            {
                if (query_attribute_key == it->first)
                {
                    tag_has_attribute = true;
                    query_attribute_value = it->second;
                }
            }
            break;
        }
    }
    if (tag_exists && tag_has_attribute)
    {
        return query_attribute_value;
    }
    return "Not Found!";
}

int fn_get_next(int &index, int &closing_line_num ,int &op_line_num )
{
    // cout << "---fn_get_next() STARTED---\n";
    // cout << "int index : "            << index            << endl ;
    // cout << "int closing_line_num : " << closing_line_num << endl ;
    // cout << "int op_line_num : "      << op_line_num      << endl ; 
    int max_children = (closing_line_num - op_line_num )/2;
    int next_tag_index_at_same_level = index + max_children + 1 ;
    return next_tag_index_at_same_level;
    // cout << "---fn_get_next() ENDED---\n";
}

bool fn_valid_child(vector<Tag> &vec_Tags, string current_tag_name, string &next_tag_name)
{
    
    bool tag_exists = false;
    bool valid_child = false;
    bool tag_has_children = false;

    
    int index ;
    for (int i = 0 ;i < (int)vec_Tags.size(); i++)
    {

        if (current_tag_name == vec_Tags[i].tag_name)
        {
            index = i ;
            tag_exists = true;
            int max_children = (vec_Tags[i].closing_line_num - vec_Tags[i].op_line_num )/2;
            tag_has_children = (max_children)?true:false ;
            break;
        }
    }

    if (tag_exists && tag_has_children)
    {
        Tag &parent_tag = vec_Tags[index] ;
        Tag &child_tag = vec_Tags[index+1] ;
        int child_index = index + 1 ; 
        /* 
        for ex:
        0 : <tag1 a1 = "A">
        1 : <tag2 a2 = "A">
        2 : </tag2>
        3 : </tag1>
        4 : <tag3 a3 = "B">

        then vec_tags will have [ tag1 , tag2 , tag3 ]
        max children for tag1  = floor( (3 - 0)/2 ) = 1
        next_tag_index_at_same_level (in the vector) = tag3's index = index of tag1 + max_c + 1
        
        */
       
       int next_tag_index_at_same_level = fn_get_next(index,parent_tag.closing_line_num,parent_tag.op_line_num) ;
       
    //    cout << "next_tag_index_at_same_level : " << next_tag_index_at_same_level << endl ;
       
        int i = 0;
        while (i < (int)next_tag_index_at_same_level)
        {
            if( next_tag_name == child_tag.tag_name)
            {
                valid_child = true ;
                // cout << next_tag_name << " is valid child of " << parent_tag.tag_name << endl ;
                break;
            }
            i = fn_get_next(  child_index , child_tag.closing_line_num , child_tag.op_line_num);
            // update to new child as well if in case it has more than one children
            child_tag = vec_Tags[i] ;
            child_index = i ; 
            // cout << "next index to be checked will be " << i << endl ;
        }
        return valid_child ;
    }
    else
    {
        return false;
    }
    
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // t1 -> no. of lines of HRML code

    // t2 -> no. of lines queries

    vector<Tag> vec_Tags;
    int t1, t2;
    cin >> t1;
    cin >> t2;

    int total_code_lines = t1;
    string code_lines[t1];
    string query_lines[t2];

    // clear the buffer

    string buffer;
    getline(cin, buffer);

    // take all the code lines at once

    int line_no = 0;
    while (t1--)
    {

        /* bool taking_tag = false;
        bool closing_tag = false; */

        getline(cin, code_lines[line_no]);
        // // cout << line_no << " : " << code_lines[line_no] << endl;
        line_no++;
        // traverse the code line
    }

    // // cout << "code lines : " << line_no << endl;
    for (int index = 0; index < line_no; index++)
    {

        // now we traverse the code_lines
        // line shouldn't be empty

        if (code_lines[index].length() > 0)
        {

            int i = 0;
            string line = code_lines[index];
            while (i < (int)code_lines[index].length())
            {
                // // cout << "----OUTER LOOP STARTED-----\n";

                // skip spaces before taking tag name

                skipSpaces(i, line);
                if (line[i] == '<')
                {
                    // we move to the next alnum value which will be tagname
                    // loop needs to manually increment int i

                    i++;
                    // // cout << " i : " << i << " Line[i] : " << line[i] << endl;

                    // skip all the spaces , for eg  [  <     tag1 value = "value" ..... ]

                    skipSpaces(i, line);
                }

                Tag new_tag = createTag(i, line, code_lines, index, total_code_lines);
                vec_Tags.push_back(new_tag);

                // // cout << "----OUTER LOOP ENDED-----\n";
                // // cout << "created a Tag | index : " << index << endl;
            }
        }
        else
        {
            // // cout << "we skipped index :" << index << endl;
        }
    }

    fn_print_Tags(vec_Tags);

    // execute the queries
    // take all the queries

    line_no = 0;
    string query;
    while (t2--)
    {
        // cout<< " while (t2--) STARTS t2 value :"<<t2 << endl ;
        int i = 0;
        getline(cin, query_lines[line_no]);
        query = query_lines[line_no];

        // // cout << line_no << " : " << query_lines[line_no] << endl;
        line_no++;

        // process the query line
        /*
        tag1.tag2~a2
        we go over the query line , get the first tag
        and then check if there's a dot (.) or a tilde ~ after it
        if its a dot then we move to the next tag provided it is valid
        if its a tilde we check for the attribute of the current one


        */
        string current_tag_name;
        string query_attribute_key;
        string query_attribute_value = "Not Found!";
        bool valid_child;

        while (i < (int)query.length())
        {
            
            string next_tag_name;
            // cout << "----while (i < query.length()) STARTED-----" << endl;
            // cout << " i : " << i << " Line["<<line_no-1<<"] : " << query_lines[line_no-1] << endl;
            // cout << "BEFORE UPDATE current_tag_name :" << current_tag_name << endl;
            current_tag_name = receiveAlNum(i, query, current_tag_name);
            // cout << "AFTER UPDATE current_tag_name :" << current_tag_name << endl;
            if (query[i] == '.')
            {
                i++;
                int k = i ;
                next_tag_name = receiveAlNum(i, query, next_tag_name);
                // // cout << "next_tag_name :" << next_tag_name << endl ;
                // query_attribute_value = "NOT CHECKED" ;

                valid_child = fn_valid_child(vec_Tags, current_tag_name, next_tag_name);
                i = k ;
                if (valid_child)
                {
                    // current_tag_name will be the next tag name after the dot (.) so just let it be 
                    
                }
                else
                {
                    // query_attribute_value = "INVALID CHILD | PARENT : " + current_tag_name + " | CHILD : " + next_tag_name;
                    query_attribute_value = "Not Found!";
                }
                continue ;
            }
            else if (query[i] == '~')
            {
                i++;
                query_attribute_key = receiveAlNum(i, query, query_attribute_key);
                // cout << "query_attribute_key : " << query_attribute_key << endl;
                query_attribute_value = fn_check_key_exists(vec_Tags, current_tag_name, query_attribute_key);
            }

            // below // // cout is for debug only

            // cout << "INSIDE LOOP query_attribute_value : " << query_attribute_value << endl;
            i++;

            // current_tag_name = "" ;

            // cout << "----while (i < query.length()) ENDED-----" << endl;
        }
        // cout << "OUTSIDE WHILE LOOP query_attribute_value : " << query_attribute_value << endl;
        if(query_attribute_value != "Not Found!")
        {
            cout << query_attribute_value << endl;
            
        }
        else{
            cout << "Not Found!"<< endl; 
        }
        // cout<< " while (t2--) ENDS t2 value :"<<t2 << endl ;
    }
    // cout<<"ok PROGRAM ENDS" << endl; 
}



