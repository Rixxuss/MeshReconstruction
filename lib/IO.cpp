#include <stdexcept>
#include <fstream>
#include "IO.h"
#include <iostream>

using namespace std;

void MeshReconstruction::WriteObjFile(Mesh const &mesh, string const &fileName) {

    std::ofstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Could not write obj file.");
    }

    file << "# " << mesh.vertices.size() << " vertices, " << mesh.triangles.size() << " triangles\n\n";

    // Write vertices
    for (const auto& v : mesh.vertices) {
        file << "v " << v.x << " " << v.y << " " << v.z << "\n";
    }

    // Write vertex normals
    file << "\n";
    for (const auto& vn : mesh.vertexNormals) {
        file << "vn " << vn.x << " " << vn.y << " " << vn.z << "\n";
    }

    // Write triangles (1-based)
    file << "\n";
    for (const auto& t : mesh.triangles) {
        file << "f " << t[0] + 1 << "//" << t[0] + 1 << " "
             << t[1] + 1 << "//" << t[1] + 1 << " "
             << t[2] + 1 << "//" << t[2] + 1 << "\n";
    }

    file.close();

//    // FILE faster than streams.
//
//    FILE *file = fopen(fileName.c_str(), "w");
//    if (file == nullptr) {
//        throw std::runtime_error("Could not write obj file.");
//    }
//
//    // write stats
//    fprintf(file, "# %d vertices, %d triangles\n\n",
//            static_cast<int>(mesh.vertices.size()),
//            static_cast<int>(mesh.triangles.size()));
//
//    // vertices
//    for (auto vi = 0; vi < mesh.vertices.size(); ++vi) {
//        auto const &v = mesh.vertices.at(vi);
//        fprintf(file, "v %f %f %f\n", v.x, v.y, v.z);
//    }
//
//    // vertex normals
//    fprintf(file, "\n");
//    for (auto ni = 0; ni < mesh.vertices.size(); ++ni) {
//        auto const &vn = mesh.vertexNormals.at(ni);
//        fprintf(file, "vn %f %f %f\n", vn.x, vn.y, vn.z);
//    }
//
//    // triangles (1-based)
//    fprintf(file, "\n");
//    for (auto ti = 0; ti < mesh.triangles.size(); ++ti) {
//        auto const &t = mesh.triangles.at(ti);
//        fprintf(file, "f %d//%d %d//%d %d//%d\n",
//                t[0] + 1, t[0] + 1,
//                t[1] + 1, t[1] + 1,
//                t[2] + 1, t[2] + 1);
//    }
//
//    fclose(file);
}